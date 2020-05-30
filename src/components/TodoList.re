open ReactNative;
open ReactUtils;
open ReasonReact;
open Types;

[@react.component]
let make = (~todos=?, _) => {
  switch (todos) {
  | Some(todos) =>
    Js.log("Todos are ");
    Js.log(List.length(todos));
    <View>
      {List.mapi(
         (i, todo) => {
           Js.log(todo);
           <View key={string_of_int(i)}>
             <Text> {toStr(todo.text)} </Text>
           </View>;
         },
         todos,
       )
       |> Array.of_list
       |> array}
    </View>;
  | None => <View> <Text> {toStr("No todos here!")} </Text> </View>
  };
};