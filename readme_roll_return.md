# 🎲 Roll and Return

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green.svg?style=for-the-badge)

**Juego de dados estratégico de dos jugadores**

[Características](#características) • [Instalación](#instalación) • [Cómo Jugar](#cómo-jugar) • [Equipo](#equipo)

</div>

---

## 📖 Descripción

**Roll and Return** es un juego de dados para dos jugadores desarrollado en C++ como proyecto integrador para la materia Programación I. Los jugadores compiten en diferentes fases para acumular monedas de oro y obtener la mayor cantidad de puntos de victoria.

El juego se divide en tres fases principales:
- **Fase Inicial**: 3 competencias por monedas adicionales
- **Fase de Búsqueda de Tesoros**: 3 rondas explorando cofres con llaves y gemas
- **Fase Final**: Cálculo de puntos de victoria y determinación del ganador

---

## 🎯 Características

### ✨ Mecánicas del Juego

- **Sistema de Competencias**
  - Competencia #1: Lanzamiento de 1 dado
  - Competencia #2: 3 dados sin repetir
  - Competencia #3: Escaleras (4 tipos válidos)

- **Sistema de Tesoros**
  - 3 tipos de cofres (Madera, Piedra, Metal)
  - Sistema de llaves guardadas
  - 3 tipos de gemas (Esmeraldas, Rubíes, Diamantes)
  - Valores de venta dinámicos

- **Sistema de Puntuación**
  - Múltiples bonificaciones
  - Paquetes de monedas
  - Bonus por logros especiales
  - Sistema de empates

### 🛠️ Características Técnicas

- Desarrollado en **C++** con aplicación de consola
- Uso de **funciones** y **vectores**
- Sin variables globales
- Lanzamiento aleatorio de dados con `srand` y `rand`
- Interfaz mejorada con **rlutil.h** (colores y formato)
- Código modular y organizado

---

## 🎮 Cómo Jugar

### Reglas Básicas

**Fase Inicial**
1. Cada jugador comienza con 150 monedas de oro
2. Compiten en 3 competencias por 150 monedas adicionales

**Competencia #1**
- Ambos lanzan 1 dado
- Mayor valor: +50 monedas
- Empate: +25 monedas cada uno

**Competencia #2**
- Ambos lanzan 3 dados
- Gana quien tenga todos los valores diferentes: +50 monedas
- Si ambos logran valores diferentes: +25 cada uno

**Competencia #3**
- Ambos lanzan 3 dados
- Gana quien obtenga una escalera: +50 monedas
- Escaleras válidas:
  - `{1,2,3}` → Escalera baja
  - `{4,5,6}` → Escalera alta
  - `{2,4,6}` → Escalera par
  - `{1,3,5}` → Escalera impar

**Fase de Búsqueda de Tesoros**
- 3 rondas (Cofre de Madera, Piedra, Metal)
- Cada jugador lanza 5 dados por ronda
- Dados 1-3: Llaves (Madera, Piedra, Metal)
- Dados 4-6: Gemas (Esmeraldas, Rubíes, Diamantes)

**Valores de Venta:**
| Item | Valor |
|------|-------|
| Llave de Madera | 10 monedas |
| Llave de Piedra | 20 monedas |
| Llave de Metal | 30 monedas |
| Esmeraldas | 40 monedas |
| Rubíes | 50 monedas |
| Diamantes | 60 monedas |

**Mecánica de Cofres:**
- Necesitas la llave correcta para abrir cada cofre
- Si abres: vendes gemas y llaves sobrantes
- Si no abres: puedes guardar UNA llave o vender todas

**Fase Final - Puntos de Victoria (PDV)**
| Logro | PDV |
|-------|-----|
| Más monedas en Fase Inicial | +100 |
| Por cada 30 monedas (paquetes) | +50 |
| Por cada moneda suelta | +1 |
| Abrir todos los cofres | +200 |
| Vender todos los tipos de gemas | +200 |
| Abrir cofre con llave guardada | +300 |

**Ganador:**
- Mayor PDV gana
- Empate en PDV: gana quien abrió todos los cofres
- Si persiste empate: resultado empate

---

## 📥 Instalación

### Requisitos Previos

- Compilador C++ (C++11 o superior)
- Visual Studio 2019/2022, Code::Blocks, o g++
- Biblioteca `rlutil.h` (incluida en el proyecto)

### Pasos de Instalación

1. **Clonar el repositorio**
```bash
git clone https://github.com/tu-usuario/roll-and-return.git
cd roll-and-return
```

2. **Estructura del proyecto**
```
roll-and-return/
│
├── main.cpp              # Punto de entrada del programa
├── Funciones.h           # Declaraciones de funciones
├── Funciones.cpp         # Implementaciones generales
├── competencia_1.cpp     # Lógica de competencia #1
├── competencia_2.cpp     # Lógica de competencia #2
├── competencia_3.cpp     # Lógica de competencia #3
├── fase_busqueda_tesoro.cpp  # Fase de tesoros
└── rlutil.h              # Biblioteca para colores
```

3. **Compilar el proyecto**

**Con g++:**
```bash
g++ -o RollAndReturn main.cpp Funciones.cpp competencia_1.cpp competencia_2.cpp competencia_3.cpp fase_busqueda_tesoro.cpp
```

**Con Visual Studio:**
- Abrir el archivo `.sln`
- Compilar (F7) y ejecutar (F5)

4. **Ejecutar**
```bash
./RollAndReturn
```

---

## 🎨 Capturas de Pantalla

### Menú Principal
```
██████╗  █████╗ ███╗   ██╗██████╗ ██████╗ 
██╔══██╗██╔══██╗████╗  ██║██╔══██╗██╔══██╗
██████╔╝███████║██╔██╗ ██║██║  ██║██████╔╝
██╔══██╗██╔══██║██║╚██╗██║██║  ██║██╔══██╗
██║  ██║██║  ██║██║ ╚████║██████╔╝██║  ██║
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝

1 - JUGAR
2 - ESTADÍSTICAS
3 - CRÉDITOS
---------------------
0 - SALIR
```

---

## 👥 Equipo

<table>
  <tr>
    <td align="center">
      <img src="https://via.placeholder.com/100" width="100px;" alt=""/><br />
      <sub><b>Alberto Alejandro Ponce</b></sub><br />
      <sub>Legajo: [COMPLETAR]</sub>
    </td>
    <td align="center">
      <img src="https://via.placeholder.com/100" width="100px;" alt=""/><br />
      <sub><b>German Agustin Giujusa</b></sub><br />
      <sub>Legajo: [COMPLETAR]</sub>
    </td>
    <td align="center">
      <img src="https://via.placeholder.com/100" width="100px;" alt=""/><br />
      <sub><b>Nicolás Agustin Legal</b></sub><br />
      <sub>Legajo: [COMPLETAR]</sub>
    </td>
    <td align="center">
      <img src="https://via.placeholder.com/100" width="100px;" alt=""/><br />
      <sub><b>Santiago Centurion</b></sub><br />
      <sub>Legajo: [COMPLETAR]</sub>
    </td>
  </tr>
</table>

---

## 🏛️ Información Académica

- **Institución:** Universidad Tecnológica Nacional - Facultad Regional General Pacheco (UTN-FRGP)
- **Carrera:** Tecnicatura Universitaria en Programación
- **Materia:** Programación I
- **Año:** 2025 - 2do Cuatrimestre
- **Tipo:** Trabajo Práctico Integrador

---

## 📚 Conceptos Aplicados

Este proyecto demuestra el uso de:

- ✅ **Estructuras de Control**: if-else, switch-case, bucles for/while
- ✅ **Funciones**: Modularización y reutilización de código
- ✅ **Arrays**: Vectores para almacenar datos de jugadores
- ✅ **Paso por Referencia**: Modificación de variables entre funciones
- ✅ **Números Aleatorios**: Generación con srand/rand
- ✅ **Entrada/Salida**: Manejo de cin/cout
- ✅ **Lógica de Juegos**: Implementación de reglas complejas
- ✅ **Diseño Modular**: Separación en múltiples archivos

---

## 🔧 Tecnologías

- **Lenguaje:** C++
- **Estándar:** C++11
- **Bibliotecas:**
  - `<iostream>` - Entrada/salida
  - `<cstdlib>` - Funciones generales
  - `<ctime>` - Manejo de tiempo
  - `<string>` - Manejo de cadenas
  - `rlutil.h` - Utilidades de consola (colores y formato)

---

## 📝 Licencia

Este proyecto fue desarrollado con fines educativos para la UTN-FRGP.

---

## 🤝 Contribuciones

Este es un proyecto académico cerrado. No se aceptan contribuciones externas, pero siéntete libre de hacer un fork para uso educativo.

---

## 📞 Contacto

Para consultas sobre el proyecto, contactar a través de:
- **Institución:** UTN - Facultad Regional General Pacheco
- **Materia:** Programación I - 2025 2C

---

<div align="center">

**⭐ Si te gustó el proyecto, dale una estrella! ⭐**

Desarrollado con ❤️ por estudiantes de la UTN-FRGP

</div>