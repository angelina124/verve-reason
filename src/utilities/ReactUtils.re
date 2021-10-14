open Actions;
open Constants;
open Data;
open Screens;
open Settings;

external toStr: string => React.element = "%identity";
external toObject: 'a => Js.t({..}) = "%identity";

let getID = ( user ) => {
    Js.log(user);
    switch(user) { 
        | Some(u) => u._id
        | None => "123"
    } 
}


let getDefaultTodoList = ( user ) => {
    Js.log(user);
    switch(user) { 
        | Some(u) => {
            let todolist = u.todolists[0];
            todolist._id
        }
        | None => "123"
    } 
} 