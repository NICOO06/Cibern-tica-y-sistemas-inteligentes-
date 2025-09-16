# juego_vida_consola.py
import time
import copy


# Crear una cuadrícula vacía de tamaño rows x cols
def crear_cuadricula(rows, cols):
    return [[0 for _ in range(cols)] for _ in range(rows)]


# Contar vecinos vivos de la celda (r,c)
def contar_vecinos(grid, r, c):
    rows = len(grid)
    cols = len(grid[0])
    tot = 0
    for dr in (-1, 0, 1):
        for dc in (-1, 0, 1):
            if dr == 0 and dc == 0:
                continue
            rr = r + dr
            cc = c + dc
            if 0 <= rr < rows and 0 <= cc < cols:
                tot += grid[rr][cc]
    return tot


# Aplicar una generación y devolver la nueva cuadrícula
def siguiente_generacion(grid):
    rows = len(grid)
    cols = len(grid[0])
    new = crear_cuadricula(rows, cols)
    for r in range(rows):
        for c in range(cols):
            vecinos = contar_vecinos(grid, r, c)
            if grid[r][c] == 1:
                # supervivencia
                new[r][c] = 1 if vecinos in (2, 3) else 0
            else:
                # nacimiento
                new[r][c] = 1 if vecinos == 3 else 0
    return new


# Imprimir la cuadrícula en consola
def imprimir(grid):
    for row in grid:
        line = ''.join('█' if cell else ' ' for cell in row)
        print(line)


# Ejemplo: colocar un glider
def poner_glider(grid, top, left):
    pattern = [(0,1),(1,2),(2,0),(2,1),(2,2)]
    for dr, dc in pattern:
        grid[top+dr][left+dc] = 1


if __name__ == '__main__':
    rows, cols = 20, 40
    g = crear_cuadricula(rows, cols)
    poner_glider(g, 2, 2)


    try:
        while True:
            print('\033[H\033[J', end='') # limpiar pantalla en muchas terminales
        imprimir(g)
        g = siguiente_generacion(g)
        time.sleep(0.2)
    except KeyboardInterrupt:
        print('\nDemo terminada')