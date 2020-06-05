open Types;

/* 
  [toStr str] is the React.element representation of [str]. 
  Use this when rendering strings in <Text> components.
*/
let toStr: string => React.element;

/*
[newTodoToObject new_todo] is the JavaScript object representation of
the todo. 
*/
let newTodoToObject: new_todo => Js.t({..});