# Compilador
CC = g++

# Opciones de compilación
CFLAGS = -std=c++17 -pthread -Wall

# Rutas a los archivos fuente

FRONTEND_DIR = Frontend
BACKEND_DIR = Backend
CACHE_DIR = Cache

# Nombres de los archivos fuente
SEARCHER_SRC = $(FRONTEND_DIR)/searcher.cpp
MEMCACHE_SRC = $(CACHE_DIR)/memcache.cpp
INVERTED_INDEX_SRC = $(BACKEND_DIR)/invertedindex.cpp

# Directorios de destino para los ejecutables
OUTPUT_DIR_SEARCHER = $(FRONTEND_DIR)
OUTPUT_DIR_MEMCACHE = $(CACHE_DIR)
OUTPUT_DIR_INVERTED_INDEX = $(BACKEND_DIR)

# Ejecutables
SEARCHER_EXECUTABLE = $(OUTPUT_DIR_SEARCHER)/searcher
MEMCACHE_EXECUTABLE = $(OUTPUT_DIR_MEMCACHE)/memcache
INVERTED_INDEX_EXECUTABLE = $(OUTPUT_DIR_INVERTED_INDEX)/invertedindex

.PHONY: all clean

all: $(SEARCHER_EXECUTABLE) $(MEMCACHE_EXECUTABLE) $(INVERTED_INDEX_EXECUTABLE)

$(SEARCHER_EXECUTABLE): $(SEARCHER_SRC)
	$(CC) $(CFLAGS) $< -o $@ -lstdc++fs

$(MEMCACHE_EXECUTABLE): $(MEMCACHE_SRC)
	$(CC) $(CFLAGS) $< -o $@ -lstdc++fs

$(INVERTED_INDEX_EXECUTABLE): $(INVERTED_INDEX_SRC)
	$(CC) $(CFLAGS) $< -o $@ -lstdc++fs

run_searcher: $(SEARCHER_EXECUTABLE)
	./$<

run_memcache: $(MEMCACHE_EXECUTABLE)
	./$<

run_inverted_index: $(INVERTED_INDEX_EXECUTABLE)
	./$<

clean:
	rm -f $(SEARCHER_EXECUTABLE) $(MEMCACHE_EXECUTABLE) $(INVERTED_INDEX_EXECUTABLE)

# Borra los archivos ejecutables y luego los vuelve a compilar
rebuild: clean all