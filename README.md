# Automatic Irrigation

In the following automation, the irrigation of plants is done with the data collected from the soil.

## How it works

It waters the plants in the morning, noon and forenoon. If the soil is already wet then it checks within an hour continously until night time to water it when needed.

The amount of water needed can also be adjusted according the requirements of the plants.

This setup can be extended to larger fields.

> The system does the following:
> * Gives the soil moisture value in the soil where 400-600 is wet and above 800 is dry.
> *  If the soil moisture sensor detects the soil is dry during the watering period then it switches on the pump and the plants are watered. This is done to avoid excess watering of the plant in case precipitation occurs.
> * It checks the moisture every 30 mins during the watering period.
> * The timing is kept in real time using the RTC(Real Time Clock) module.  


## Hardware Requirements

- Arduino Uno (or compatible board)
- Soil Moisture Sensor (Capacitive Preferred)
- Motor Driver (12V or as required by the motor)
- DC Water Pump 
- DC Power Adapter
- Buck to Buck Converter or Battery(To power the board and motors)
- LCD Module
- RTC Module
- Relay Module
- Diode , Transistor and 1k ohm resistor (if the relay doesn't have a module)
- Jumper Wires
- Vinyl Tubes


## Arduino Libraries Required




## Pin Configurations

### DC Power Adapter

| DC Power Adapter | To |
|-----------|-------------|
| Positive Terminal | Positive of Pump |
| Positive Terminal | Negative of IN of Buck Converter |
| Negative Terminal | NO or NC of Relay |
| Negative Terminal | Positive of IN of Buck Converter |

### DC Water Pump

| DC Water Pump | To |
|-----------|-------------|
| Positive Terminal | Positive of Motor |
| Negative Terminal | COM of Relay |

### Buck to Buck Converter

| BcB Converter | To |
|-----------|-------------|
| Positive Terminal IN | Negaitive of DC Adapter |
| Positive Terminal OUT| Negative of Power Jack |
| Negative Terminal IN | Positive of DC Adapter |
| Negative Terminal OUT| Positive of Power Jack |

### LCD Module 

Please Refer to [this](https://howtomechatronics.com/tutorials/arduino/lcd-tutorial/) if it is without i2c module.

If it is with an i2c module, then refer to [this](https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/).

### RTC Module

| RTC | To |
|-|-|
| SCL | SCL of Arduino |
| SDA | SDA of Arduino |
| VCC | VCC of Arduino |
| GND | GND of Arduino |

### Relay with Module

| Relay | To |
|-----------|-------------|
| NO or NC | Negative of Adapter |
| COM | Negative of Pump |
| VCC | 5V of Arduino |
| GND | Ground of Arduino |
| IN | Arduino Pin 9 |

### Relay without Module

| Relay | To |
|-----------|-------------|
| NO or NC | Negative of DC Adapter |
| COM | Negative of Pump |
| Coil 1 | 5V of Arduino |
| Coil 2 | Anode of Diode |

### If relay is without module

#### Diode 

| Diode | To |
|-----------|-------------|
| Anode | Coil 2 of Relay |
| Anode | Collector of Transistor |
| Cathode | 5V of Arduino |

#### Transistor 

| Transistor | To |
|-----------|-------------|
| Collector | Anode of Diode |
| Collector | Coil 2 of Relay |
| Base | 1k ohm Resistor |
| Emitter | Ground of Arduino |

#### 1k ohm Resistor

| Resistor | To |
|-----------|-------------|
| 1 | Base of Transistor |
| 2 | Arduino Pin 9 |


## Setup & Installations



## Troubleshooting


