import math


def dist(a, b) -> float:
    return math.sqrt(((b[0] - a[0]) ** 2) + ((b[1] - a[1]) ** 2))


def bruto(x):
    n = len(x)
    ponto1 = []  # lista que recebe os pontos do par mais próximo
    ponto2 = []
    distmin = 10000000000000  # inicializar com distância muito grande
    for i in range(0, n - 1):  # comparar todos os pares possíveis
        for j in range(i + 1, n):
            if dist(x[i], x[
                j]) < distmin:  # se a distância do par testado for menor que o provisório, armazenar o par e a distância
                ponto1 = list(x[i])
                ponto2 = list(x[j])
                distmin = dist(x[i], x[j])
            elif dist(x[i],
                      x[j]) == distmin:  # em caso de empate, adicionar pontos às listas; distância permanece a mesma
                ponto1.append(list(x[i]))
                ponto2.append(list(x[j]))
    return (ponto1, ponto2, distmin)  # retorna os pontos e a distância entre eles


def pardiv(x, partes):
    n = len(x)
    beg = min(x)[0]  # menor valor da primeira coordenada
    end = max(x)[0]  # maior valor da primeira coordenada
    ampl = float(end - beg)  # diferença entre menor e maior valores
    ponto1 = []  # lista que recebe os pontos do par mais próximo
    ponto2 = []
    distmin = 10000000000000  # inicializar com distância muito grande
    for i in range(1, partes + 1):  # particionamento; 'partes' = número de subconjuntos
        end = min(x)[0] + (i * ampl / partes)  # dividir a amplitude em subconjuntos igualmente espaçados
        part = []
        for j in range(0, n):  # define cada subconjunto 'part'
            if beg <= x[j][0] <= end:
                part.append(x[j])
        if bruto(part)[2] < distmin:  # dentro de cada 'part', proceder por força bruta
            ponto1 = bruto(part)[0]
            ponto2 = bruto(part)[1]
            distmin = bruto(part)[2]
        cross = []
        for k in range(0,
                       n):  # 'cruzamentos': a partir da divisão anterior, fazer força bruta para todos os pontos com distância menor que 'distmin' na primeira coordenada
            if end - distmin <= x[k][0] <= end + distmin:
                cross.append(x[k])
        if bruto(cross)[2] < distmin:
            ponto1 = bruto(cross)[0]
            ponto2 = bruto(cross)[1]
            distmin = bruto(cross)[2]
        beg = end  # ir para o próximo subconjunto, repetir até chegar ao fim dos dados
    return (ponto1, ponto2, distmin)


# Min range to calculation
min_range = 10000
# Infinity loop
while True:
    tests = int(input())
    # Break program if 0 tests
    if tests == 0:
        break
    # Declare array of coordinates
    coordinates = []
    # Read coordinates
    for i in range(0, tests):
        line = input().split(' ')
        x, y = float(line[0]), float(line[1])
        coordinates.append((x, y))
    # Insert in array of distances
    if len(coordinates) == 0:
        print('INFINITY')
        continue
    minimal_distance = pardiv(coordinates, 50)[2]
    print('INFINITY' if minimal_distance > min_range else '{:.4f}'.format(minimal_distance))
