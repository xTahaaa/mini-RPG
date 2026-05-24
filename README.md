# ⚔️Last Stand Arena 
![C++](https://img.shields.io/badge/C++-17-00599C?style=flat&logo=cplusplus&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-3.10+-064F8C?style=flat&logo=cmake&logoColor=white)
![Plateforme](https://img.shields.io/badge/plateforme-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey?style=flat)

Un RPG d'arène au tour par tour écrit en C++17. Choisis ton héros, affronte un ennemi aléatoire et survive grâce à ta vitesse, tes stats et un peu de chance.
 
## 🎮 Gameplay
 
Chaque partie oppose ton héros à un ennemi tiré au sort. Celui qui a la vitesse la plus élevée attaque en premier. Le combat se déroule tour par tour jusqu'à ce qu'un des deux tombe.
 
---
## 🧱 Concepts POO utilisés

| Concept | Implémentation |
|---|---|
| Héritage | `Mage`, `Guerrier`, `Archer`, `Dragon`, `Titan` héritent de `Character` |
| Polymorphisme | `attackTarget()` surchargée dans chaque sous-classe |
| Encapsulation | Attributs protégés avec getters/setters |
| Classe abstraite | `Character` avec `attackTarget()` pure virtuelle |
| Polymorphisme dynamique | `getMagicResistance()` surchargée dans `Dragon` et `Titan` sans if/switch sur le type |

## 🧙 Classes de héros
 
| Classe | PV(HP) | Attaque | Défense | Vitesse | Points forts |
|----------|----|---------|---------|---------|-------------------------------|
| Mage | 150 | 35 | 8 | 10 | Gros dégâts, 20% de crit (×2) |
| Archer | 150 | 22 | 8 | 18 | Le plus rapide, 35% de crit (×2) |
| Guerrier | 180 | 25 | 15 | 8 | Le plus résistant, +5 dégâts fixes |
 
---
 
## 👹 Ennemis
 
| Ennemi | PV(HP) | Attaque | Défense | Vitesse | Capacité spéciale |
|--------|-----|---------|---------|---------|----------------------------------|
| Dragon | 160 | 28 | 10 | 10 | 20% de chance de souffle de feu (×1.5) |
| Titan | 200 | 22 | 15 | 5 | 15% de chance d'écrasement (×2) |
 
L'ennemi est choisi aléatoirement au début de chaque session.
 
---
## ⚙️ Mécaniques de combat
 
- **Formule de dégâts** : `dégâts_réels = attaque - défense` (minimum 0)
- **Système de vitesse** : le personnage le plus rapide attaque en premier à chaque tour
- **Coups critiques** : chaque classe et ennemi a une chance de multiplier ses dégâts
- **Inventaire** : chaque personnage démarre avec 3 objets (cosmétique / usage futur)
- **XP** : les personnages gagnent de l'XP à la création (base pour un futur système de niveaux)
- **Résistances magiques** : le Mage peut lancer des sorts (feu, glace, foudre, terre). Chaque ennemi possède ses propres résistances via polymorphisme dynamique (sans if/switch sur le type)
---
## 📋 Prérequis
 
Assure-toi d'avoir les outils suivants installés avant de compiler :
 
| Outil | Version minimum | Lien |
|-------|----------------|------|
| G++ / Clang | C++17 compatible | [gcc.gnu.org](https://gcc.gnu.org) |
| CMake | 3.10+ | [cmake.org](https://cmake.org) |
| Git | toute version récente | [git-scm.com](https://git-scm.com) |
 
**Vérifier les installations :**
```bash
g++ --version
cmake --version
git --version
```
 
---
 
## 🚀 Compilation & Lancement
```bash
# 1. Cloner le dépôt
git clone https://github.com/xTahaaa/mini-RPG.git
cd mini-RPG
 
# 2. Créer le répertoire de build
mkdir build && cd build
 
# 3. Générer et compiler
cmake ..
cmake --build .
 
# 4. Lancer
./mini-RPG          # Linux/macOS
.\mini-RPG.exe      # Windows
```
 ## 📁 Structure du projet
 
```
mini-RPG/
├── src/
│   ├── main.cpp
│   ├── Character.cpp
│   ├── Heroes.cpp
│   └── Enemies.cpp
├── include/ 
│   ├── Character.h
│   ├── Heroes.h
│   └── Enemies.h
└── CMakeLists.txt
```
 
---
## 👤 Fait par :
+ [@xTahaaa](https://github.com/xTahaaa)

+ [@Mouhssine-Tazrakine](https://github.com/Mouhssine-Tazrakine)

+ [@AdamAch-7](https://github.com/AdamAch-7)

+ [@zineelaabidinesadati8](https://github.com/zineelaabidinesadati8)
