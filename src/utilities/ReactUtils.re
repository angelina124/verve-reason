open Types;

external toStr: string => React.element = "%identity";
external newTodoToObject: new_todo => Js.t({..}) = "%identity";