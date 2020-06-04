open Routes;
open Types;
open ReactUtils;

let fetchRewards = (~uID, ~dispatch) =>
  Js.Promise.(
    Axios.get(routes.rewards ++ uID)
    |> then_(res => {
         let ts = res##data##rewards;
         Js.log(ts);
         let rewardList = Js.Array.reduceRight((a, t) => [t, ...a], [], ts);
         resolve(dispatch(FETCH_REWARDS(rewardList)));
       })
    |> catch(err => {
         Js.log(err);
         resolve(dispatch(ERROR_FETCHING_REWARDS));
       })
    |> ignore
  );

let addTodo = (~text: string, ~points: int, ~goToTodoList, ~todoID, ~dispatch) =>
  Js.Promise.(
    Axios.postData(routes.addTodo ++ todoID, newTodoToObject({text, points}))
    |> then_(res => resolve(goToTodoList()))
    |> catch(_ => resolve(dispatch(ERROR_ADDING_TODO)))
    |> ignore
  );

let fetchTodos = (~todoID, ~dispatch) =>
  Js.Promise.(
    Axios.get(routes.todos ++ todoID)
    |> then_(res => {
         let ts = res##data##todos;
         Js.log(ts);
         let todoList = Js.Array.reduceRight((a, t) => [t, ...a], [], ts);
         resolve(dispatch(FETCH_TODOS(todoList)));
       })
    |> catch(err => {
         Js.log(err);
         resolve(dispatch(ERROR_FETCHING_TODOS));
       })
    |> ignore
  );
let completeTodo = (~todoID: string, ~dispatch) =>
  Js.Promise.(
    Axios.post(routes.completeTodo ++ todoID)
    |> then_(res => {
         let todo = res##data##todoDoc;
         resolve(dispatch(COMPLETE_TODO(todo)));
       })
    |> catch(_ => resolve(dispatch(ERROR_COMPLETING_TODO)))
    |> ignore
  );