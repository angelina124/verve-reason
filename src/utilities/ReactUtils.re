open Actions;
open Data;
open Screens;
open Settings;

external toStr: string => React.element = "%identity";
external toObject: 'a => Js.t({..}) = "%identity";