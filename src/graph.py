import pandas as pd
import matplotlib.pyplot as plt

# Carrega os dados do arquivo CSV e pula a primeira linha
df = pd.read_csv("output.csv", skiprows = 1)

# Remove espaços em branco nos nomes das colunas
df.columns = df.columns.str.strip()

# Adiciona manualmente os nomes das colunas
df.columns = ['Tamanho', 'Bubblesort', 'Insertionsort', 'HeapsortMax', 'Mergesort', 'Quicksort', 'RadixSort']

# Imprime as colunas disponíveis que foram representadas no gráfico
print(df.columns)

# Plota os dados
fig, ax = plt.subplots(figsize=(10, 6))

# Adiciona uma linha para cada método de ordenação
ax.plot(df['Tamanho'], df['Bubblesort'], label='Bubblesort')
ax.plot(df['Tamanho'], df['Insertionsort'], label='Insertionsort')
ax.plot(df['Tamanho'], df['HeapsortMax'], label='Heapsort')
ax.plot(df['Tamanho'], df['Mergesort'], label='Mergesort')
ax.plot(df['Tamanho'], df['Quicksort'], label='Quicksort')
ax.plot(df['Tamanho'], df['RadixSort'], label='RadixSort')

# Adiciona rótulos e título
ax.set_title('Comparação dos Métodos de Ordenação')
ax.set_xlabel('Tamanho do Conjunto de Dados')
ax.set_ylabel('Esforço Computacional/Número de Iterações')
ax.legend()
plt.yscale('log')

# Exibe o gráfico
plt.show()