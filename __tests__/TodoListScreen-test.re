open Jest;
open React;
open TodoListScreen;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~title="Test", ~handleClick=(_evt) => (), ()) =>
  Enzyme.shallow(<DummyComponent title handleClick />);
 
let header = (wrapper) =>
wrapper
  |> Enzyme.Shallow.find("#header")
  |> Enzyme.Shallow.first;
 
let listItems = (wrapper) =>
  wrapper
  |> Enzyme.Shallow.find("#list")
  |> Enzyme.Shallow.children;
 
describe("DummyComponent", () => {
  open Expect;
 
  test("renders a #header", () => {
    let title = "A test title";
    let wrapper = setup(~title, ());
    let headerNodes = wrapper |> header;
    expect(Enzyme.Shallow.length(headerNodes)) |> toBe(1)
  });
 
  test("has the expected h1 tag in the #header", () => {
    let title = "A test title";
    let wrapper = setup(~title, ());
    let expectedNode = <h1> (ReasonReact.stringToElement(title)) </h1>;
    expect(Enzyme.Shallow.contains(expectedNode, wrapper)) |> toBe(true)
  });
 
  test("initially has its `clicked` state set to false", () => {
    let wrapper = setup();
    let {clicked}: DummyComponent.state = Enzyme.Shallow.state(wrapper);
    expect(clicked) |> toBe(false)
  });
 
  test("folds left properly", () => {
    let items = setup() |> listItems;
    let result = Enzyme.Shallow.foldLeft((text, node) => text ++ Enzyme.Shallow.text(node), "", items);
    expect(result) |> toBe("OneTwoThree")
  });
 
  test("maps properly", () => {
    let items = setup() |> listItems;
    let result = Enzyme.Shallow.map(node => Enzyme.Shallow.text(node), items);
    expect(result) |> toEqual([|"One", "Two", "Three"|])
  });
});
