# Digital Ecosystem Simulator

A terminal-based ecosystem simulation written in C++ that models interactions between plants, herbivores, and carnivores within a dynamic environment.

The simulation demonstrates emergent behavior through autonomous agents competing for resources, reproducing, and adapting to changing environmental conditions.

---

## Features

### Plant System
- Plants randomly spread throughout the environment
- Growth rates depend on weather conditions
- Creates renewable food resources

### Herbivore System
- Search for nearby plants
- Consume plants to gain energy
- Reproduce when energy thresholds are met
- Die from starvation

### Carnivore System
- Hunt herbivores for energy
- Reproduce when energy thresholds are reached
- Population fluctuates naturally

### Dynamic Weather System

Weather states:

- Sunny
- Rain
- Drought

Weather directly influences ecosystem growth and population dynamics.

### Simulation Engine

- Continuous real-time updates
- Autonomous agent interactions
- Emergent ecosystem behavior
- Terminal-based visualization
