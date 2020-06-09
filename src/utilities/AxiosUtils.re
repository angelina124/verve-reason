open Routes;
open Actions;
open Data;
open Screens;
open Settings;
open ReactUtils;

let fetchRewards = (~uID: id, ~dispatch) =>
  Js.Promise.(
    Axios.get(routes.rewards ++ uID)
    |> then_(res => {
         let ts = res##data##rewards;
         Js.log(ts);
         let rewardList = Js.Array.reduceRight((a, t) => [t, ...a], [], ts);
         resolve(dispatch(FETCHED_REWARDS(rewardList)));
       })
    |> catch(err => {
         Js.log(err);
         resolve(dispatch(ERROR_FETCHING_REWARDS));
       })
    |> ignore
  );

let addTodo = (~text, ~points, ~goToTodoList, ~todoListID, ~dispatch) =>
  Js.Promise.(
    Axios.postData(routes.todos ++ todoListID, toObject({text, points}))
    |> then_(res => resolve(goToTodoList()))
    |> catch(_ => resolve(dispatch(ERROR_ADDING_TODO)))
    |> ignore
  );

let addReward = (~text, ~points, ~goToTodoList, ~userID, ~dispatch) =>
  Js.Promise.(
    Axios.postData(routes.rewards ++ userID, toObject({text, points}))
    |> then_(res => resolve(goToTodoList()))
    |> catch(_ => resolve(dispatch(ERROR_ADDING_REWARD)))
    |> ignore
  );

let fetchTodos = (~todoListID: id, ~dispatch) =>
  Js.Promise.(
    Axios.get(routes.todos ++ todoListID)
    |> then_(res => {
         let ts = res##data##todos;
         Js.log(ts);
         let todoList = Js.Array.reduceRight((a, t) => [t, ...a], [], ts);
         resolve(dispatch(FETCHED_TODOS(todoList)));
       })
    |> catch(err => {
         Js.log(err);
         resolve(dispatch(ERROR_FETCHING_TODOS));
       })
    |> ignore
  );

let completeTodo = (~todoID: id, ~dispatch) =>
  Js.Promise.(
    Axios.post(routes.completeTodo ++ todoID)
    |> then_(res => {
         let todo = res##data##todoDoc;
         resolve(dispatch(COMPLETED_TODO(todo)));
       })
    |> catch(_ => resolve(dispatch(ERROR_COMPLETING_TODO)))
    |> ignore
  );

let userPost = (~username, ~password, ~dispatch, ~route) =>
  Js.Promise.(
    Axios.postData(route, toObject({username, password}))
    |> then_(res => {
         let user = res##data##user;
         resolve(dispatch(`LOGGED_IN(user)));
       })
    |> catch(err => {
         Js.log(err);
         resolve(dispatch(`ERROR));
       })
    |> ignore
  );

let login = (~username, ~password, ~dispatch) =>
  userPost(~username, ~password, ~dispatch, ~route=routes.login);

let signup = (~username, ~password, ~dispatch) =>
  userPost(~username, ~password, ~dispatch, ~route=routes.user);