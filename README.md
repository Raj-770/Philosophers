# Dining Philosophers Problem in C Using POSIX Threads

A simulation of the classic Dining Philosophers problem implemented in C using POSIX threads and mutexes. This project demonstrates synchronization and concurrency control in a multi-threaded environment.

## Table of Contents

- [Introduction](#introduction)
- [Problem Description](#problem-description)
- [Solution Overview](#solution-overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Usage](#usage)
- [Implementation Details](#implementation-details)
  - [Synchronization Mechanisms](#synchronization-mechanisms)
  - [Philosopher Routine](#philosopher-routine)
  - [Monitoring Thread](#monitoring-thread)
- [Example Output](#example-output)
- [Acknowledgments](#acknowledgments)

## Introduction

This project is an implementation of the Dining Philosophers problem, a classic synchronization problem in computer science, using C and POSIX threads. It aims to illustrate how to manage concurrent processes (threads) that share limited resources (forks) without causing deadlocks or starvation.

## Problem Description

Five philosophers are sitting around a circular table. Each philosopher has a plate of spaghetti and needs two forks to eat. Between each pair of plates, there is one fork. The philosophers must alternately think and eat. However, a philosopher can only eat if they have both the left and right forks.

The challenge is to design a protocol that allows the philosophers to eat without causing a deadlock (where no progress is possible) or starvation (where a philosopher never gets to eat).

## Solution Overview

The program creates a number of philosopher threads, each representing a philosopher. Forks are represented by mutexes. Philosophers pick up the forks (lock the mutexes) in a specific order to prevent deadlocks. The program ensures that all philosophers can eat without causing deadlocks or starvation.

## Features

- Simulates the Dining Philosophers problem with configurable parameters.
- Uses POSIX threads and mutexes for synchronization.
- Prevents deadlocks and starvation.
- Outputs the state changes of philosophers in real-time.

## Getting Started

### Prerequisites

- **C Compiler**: GCC or any compliant C99 compiler.
- **POSIX Threads Library**: Typically included with GCC (`-pthread` flag).
- **Make**: To use the provided Makefile.

### Compilation

You can compile the program using the Makefile provided:

```bash
cd philo
make
```

### Usage

Run the compiled executable with the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- **number_of_philosophers**: The total number of philosophers (and forks).
- **time_to_die**: Time (in milliseconds) a philosopher can go without eating before dying.
- **time_to_eat**: Time (in milliseconds) it takes for a philosopher to eat.
- **time_to_sleep**: Time (in milliseconds) a philosopher spends sleeping.
- **number_of_times_each_philosopher_must_eat**: (Optional) The number of times each philosopher must eat. If all philosophers eat at least this many times, the simulation ends.

**Example:**

```bash
./philo 5 800 200 200 7
```

This command starts the simulation with 5 philosophers, where each philosopher dies if they don't eat within 800ms, takes 200ms to eat, sleeps for 200ms, and the simulation ends when each philosopher has eaten 7 times.

## Implementation Details

### Synchronization Mechanisms

- **Forks**: Represented by an array of mutexes (`pthread_mutex_t`).
- **Printing Mutex**: Ensures that output statements do not interleave (`pthread_mutex_t print`).
- **Eating Mutex**: Protects shared data related to eating times (`pthread_mutex_t eat`).
- **Start Mutex**: Synchronizes the start of all philosopher threads (`pthread_mutex_t start_mutex`).
- **Copy Mutex**: Protects access to the `all_good` flag, indicating if any philosopher has died (`pthread_mutex_t copy_mutex`).

### Philosopher Routine

Each philosopher thread executes the following routine:

1. **Wait for All Threads to Be Ready**: Ensures all philosophers start simultaneously.
2. **Thinking**: The philosopher thinks for a certain duration.
3. **Picking Up Forks**: The philosopher tries to pick up the left and right forks.
4. **Eating**: Upon acquiring both forks, the philosopher eats and updates their last meal time.
5. **Sleeping**: The philosopher releases the forks and sleeps for a specified duration.
6. **Repeating**: The cycle repeats until the simulation ends.

### Monitoring Thread

A separate function `monitor_death` continuously checks if any philosopher has died or if all philosophers have eaten the required number of times. It updates the `all_good` flag accordingly, causing all threads to exit gracefully.

## Example Output

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
1 3 has taken a fork
1 3 is eating
201 1 is sleeping
201 2 has taken a fork
201 2 has taken a fork
201 2 is eating
201 3 is sleeping
201 4 has taken a fork
201 4 has taken a fork
201 4 is eating
401 2 is sleeping
401 1 is thinking
401 1 has taken a fork
401 1 has taken a fork
```

- The first number is the timestamp in milliseconds since the simulation started.
- The second number is the philosopher's ID.
- The action describes what the philosopher is doing.

## Acknowledgments

- The Dining Philosophers problem was originally formulated by **Edsger Dijkstra**.
- This project was inspired by the need to understand concurrency and synchronization in operating systems.

---
