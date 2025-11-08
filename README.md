# Roll and Return 🎲  
### Trabajo Práctico Integrador — 1° Cuatrimestre  
**Tecnicatura Universitaria en Programación — UTN**

---

## 📋 Descripción
**Roll and Return** es un juego de dados para **dos jugadores** cuyo objetivo es obtener la mayor cantidad de **Puntos de Victoria (PDV)**.  
Los PDV se consiguen principalmente acumulando monedas de oro a través de tres fases: **Inicial**, **Búsqueda de Tesoros** y **Final**.

El trabajo debe implementarse en **C++**, utilizando únicamente lo aprendido en clase:  
**condicionales, bucles, funciones separadas y vectores**.

---

## 🎯 Objetivos del proyecto
- Implementar la lógica completa del juego para dos jugadores.  
- Aplicar funciones, bucles, condicionales y vectores correctamente.  
- Organizar el código en módulos (`.h` y `.cpp`).  
- Ejecutar el juego desde consola mostrando el flujo completo y el resultado final.

---

## 🧩 Reglas del juego

### 🎲 Fase Inicial — Obtención de Monedas
- Ambos jugadores comienzan con **150 monedas**.  
- Compiten por **150 monedas adicionales** a través de **tres competencias** de dados:

| Competencia | Dados | Condición de victoria | Premio |
|--------------|-------|------------------------|--------|
| #1 | 1 dado | Gana quien obtiene el valor más alto. Empate: 25 monedas c/u. | 50 monedas |
| #2 | 3 dados | Gana quien **no tenga dados repetidos**. Si ambos cumplen: 25 monedas c/u. | 50 monedas |
| #3 | 3 dados | Gana quien obtenga una **escalera** (`1-2-3`, `4-5-6`, `2-4-6`, `1-3-5`). Si ambos cumplen: 25 monedas c/u. | 50 monedas |

---

### 💰 Fase de Búsqueda de Tesoros — Venta de Ítems
Esta fase tiene **3 rondas**, correspondientes a tres cofres:
1. **Cofre de Madera**
2. **Cofre de Piedra**
3. **Cofre de Metal**

Cada jugador lanza **5 dados** por ronda.  
Los resultados se venden por monedas de oro según el tipo:

| Tipo | Dados | Nombre | Valor |
|------|--------|--------|--------|
| Llaves | 1-3 | Madera (1): 10 monedas<br>Piedra (2): 20 monedas<br>Metal (3): 30 monedas |
| Gemas | 4-6 | Esmeralda (4): 40 monedas<br>Rubí (5): 50 monedas<br>Diamante (6): 60 monedas |

#### 🔐 Mecánica de Apertura
- Cada cofre se abre **solo con su llave correspondiente** (ej: llave de madera para cofre de madera).  
- Si el cofre **se abre**, el jugador vende **todas las gemas y las llaves no usadas**.  
- Si el cofre **no se abre**, el jugador debe elegir:
  - **Vender** las llaves no utilizadas, o  
  - **Guardar una llave** para usar en las rondas siguientes.  
- En las rondas 2 y 3, se puede usar una llave guardada para abrir el cofre.

---

### ✨ Fase Final — Cálculo de Puntos de Victoria (PDV)
Al finalizar las tres fases, se otorgan PDV según los logros del jugador:

| Descripción | PDV |
|--------------|------|
| Más monedas en la fase inicial | 100 PDV |
| Paquetes de 30 monedas | 50 PDV por paquete |
| Monedas sueltas | 1 PDV por moneda |
| Abrir todos los cofres | 200 PDV |
| Haber vendido todos los tipos de gemas | 200 PDV |
| Haber abierto un cofre con llave guardada | 300 PDV |

#### 🏆 Criterios de Victoria
1. Gana el jugador con **más PDV**.  
2. En caso de empate, gana quien haya **abierto todos los cofres**.  
3. Si el empate persiste, la partida termina en **empate**.

---

## 🧭 Flujo del juego
1. Ingresar los nombres de ambos jugadores.  
2. Ejecutar la **Fase Inicial** y asignar monedas según las competencias.  
3. Ejecutar las **3 rondas** de Búsqueda de Tesoros, mostrando resultados y decisiones.  
4. Calcular los **Puntos de Victoria** y mostrar al **ganador** con un desglose completo.

---

## 🗂 Estructura de archivos sugerida

