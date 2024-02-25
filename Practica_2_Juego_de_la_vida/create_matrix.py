import numpy as np

# Crear una matriz MxN de ceros
matriz = np.zeros((50, 50), dtype=int)

# Abrir el archivo en modo escritura
with open('data/osciladores.txt', 'w') as f:
    # Escribir las dimensiones en la primera línea
    f.write(f'{matriz.shape[0]} {matriz.shape[1]}\n')

    # Escribir la matriz
    for fila in matriz:
        f.write(''.join(map(str, fila)) + '\n')