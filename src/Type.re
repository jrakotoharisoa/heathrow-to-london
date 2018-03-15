type section = {
  a: int,
  b: int,
  c: int,
};

type roadSystem = list(section);

type label =
  | A
  | B
  | C;

type path = list((label, int));