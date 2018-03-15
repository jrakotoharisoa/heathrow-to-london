open Jest;

open Expect;

open Demo;

open Type;

describe("roadStep", () =>
  test("should return correct tuple of path", () =>
    expect({a: 50, b: 10, c: 30} |> roadStep(([], [])))
    |> toEqual(([(C, 30), (B, 10)], [(B, 10)]))
  )
);

let heathrowToLondon: Type.roadSystem = [
  {a: 50, b: 10, c: 30},
  {a: 5, b: 90, c: 20},
  {a: 40, b: 2, c: 25},
  {a: 10, b: 8, c: 0},
];

describe("optimalPath", () =>
  test("should return the optimal path", () =>
    expect(heathrowToLondon |> optimalPath)
    |> toEqual([
         (B, 10),
         (C, 30),
         (A, 5),
         (C, 20),
         (B, 2),
         (B, 8),
         (C, 0),
       ])
  )
);