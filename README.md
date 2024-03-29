# my_printf

Epitech project, 2023. By [Jimmy](https://github.com/JimmyRamsamynaick) and
[Clément](https://github.com/drawbu).


## Status

### Flag characters

- [X] #
- [X] 0
- [X] -
- [X] ' '
- [X] +
- [ ] '
- [ ] I

The two last flags were not implemented because they were not technically
possible under the restriction of the Lib C, because we could not get the
locale.

### Field width

Not implemented.

### Precision

- [X] f, F
- [X] e, E
- [ ] g, G
- [ ] a, A

### Length modifier

Not implemented.

### Conversion specifiers

- [X] d, i
- [X] o, u, x, X
- [X] e, E
- [X] f, F
- [ ] g, G
- [ ] a, A
- [X] c
- [X] s
- [X] p
- [X] n
- [X] %


## Known issues

- Padding does not work as expected on float and int if there is another flag
character.


## Bonuses

- Custom boolean converter: `%b` and `%B`. b prints "true" or "false", and B
prints "True" or "False".
