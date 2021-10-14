open Actions;
open Data;
open Screens;
open Settings;

/*
   [toStr str] is the React.element representation of [str].
   Use this when rendering strings in <Text> components.
 */
let toStr: string => React.element;

/*
 [toObject data] is the JavaScript object representation of
 the data.
 */
let toObject: 'a => Js.t({..});

/*
 getID(user) gets the id of the user if it exists
 */
let getID: option(Data.user) => id

/*
 getDefaultTodoList(user) gets the first todolist the user has
 */
let getDefaultTodoList: option(Data.user) => id