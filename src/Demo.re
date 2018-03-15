open Type;

Js.log("Hello, BuckleScript and Reason!");

let heathrowToLondon: Type.roadSystem = [
  {a: 50, b: 10, c: 30},
  {a: 5, b: 90, c: 20},
  {a: 40, b: 2, c: 25},
  {a: 10, b: 8, c: 0},
];

let sumPath: list('a) => int =
  List.fold_left((sum, (_, price)) => sum + price, 0);

let roadStep =
    ((pathA, pathB): (Type.path, Type.path), {a, b, c}: Type.section)
    : (Type.path, Type.path) => {
  let pricePathA = pathA |> sumPath;
  let pricePathB = pathB |> sumPath;
  let forwardPriceToA = pricePathA + a;
  let crossPriceToA = pricePathB + b + c;
  let forwardPriceToB = pricePathB + b;
  let crossPriceToB = pricePathA + a + c;
  let newPathToA =
    forwardPriceToA <= crossPriceToA ?
      [(A, a), ...pathA] : [(C, c), (B, b), ...pathB];
  let newPathToB =
    forwardPriceToB <= crossPriceToB ?
      [(B, b), ...pathB] : [(C, c), (A, a), ...pathA];
  (newPathToA, newPathToB);
};

let optimalPath: Type.roadSystem => Type.path =
  roadSystem => {
    let (bestAPath, bestBPath) =
      roadSystem |> List.fold_left(roadStep, ([], []));
    bestAPath |> sumPath <= (bestBPath |> sumPath) ?
      List.rev(bestAPath) : List.rev(bestBPath);
  };