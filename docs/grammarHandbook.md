# The ACalculator Grammar Handbook

## mr

Calculate the relative molecular mass.

Example:
```
>>> mr NH4HCO3
79.0553
```

## ar

Calculate the relative atomic mess.

Example:
```
>>> ar Al
26.9815
```

## rect

Calculate the diagonal of a square.

Input Type: Side length

Example:
```
>>> rect 32
45.2548
```

## exec

Execute a ACalculator script.

Input Type: file path.

## show

Show the value of a variable.

Input Type: Variable name.

Example:
```
>>> show a
(the value of this variable)
```

## let

Define a variable.

Input Type: name and a mathematical expression.

Example:
```
>>> let a = 50
>>> let b = 25 + 10
>>> let c = a + b
>>> show c
85
```

## del

Delete a variable.

Input Type: Variable name.