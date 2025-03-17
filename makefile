BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
INCLUDE_SDL_DIR = D:/SDL/SDL2-2.30.3/x86_64-w64-mingw32
PROJECT_NAME = main
RELEASE_NAME = main_release

# 定義頭文件位置
INCLUDE_FLAG = -I$(INCLUDE_DIR) -I${INCLUDE_SDL_DIR}/include/SDL2

# 定義庫文件位置
LIB_FLAGS = -L${INCLUDE_SDL_DIR}/lib/SDL2
STATIC_LIB_FLAGS = -L${INCLUDE_SDL_DIR}/lib/SDL2_static

# 鏈接庫文件
LINK_FLAG = -lmingw32 -lSDL2main -lSDL2
STATIC_LINK_FLAG = -static -lmingw32 -lSDL2main -lSDL2 -Wl,--dynamicbase -Wl,--nxcompat -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid

# 獲取所有的源文件列表
CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# 從源文件列表生成目標文件列表	
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_FILES))

# 默認目標: 生成PROJECT_NAME文件
all: ensure_build_dir $(PROJECT_NAME)

release: ensure_build_dir $(RELEASE_NAME)

ensure_build_dir:
	mkdir -p build

$(PROJECT_NAME): $(OBJ_FILES)
	g++ -g -O0 $(LIB_FLAGS) -o $@ $^ $(LINK_FLAG)
	./${PROJECT_NAME}

$(RELEASE_NAME): $(OBJ_FILES)
	g++ -O3 -s $(STATIC_LIB_FLAGS) -o $@ $^ $(STATIC_LINK_FLAG) -mwindows
	./${RELEASE_NAME}

# 模式規則: 將每個源文件編譯成對應的目標文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(INCLUDE_FLAG) -c $< -o $@

clean:
	rm -f *.exe
	rm -rf $(BUILD_DIR)
