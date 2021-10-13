open Actions;
open Data;
open Screens;
open Settings;

/*
    [fetchRewards uID dispatch] queries the database, getting the rewards
    for the user with id [uID].
    Returns a promise:
    - If the query is successful, dispatches [FETCHED_REWARDS(rewardList)]
    action where [rewardList] is the list of rewards returned by the database.
    - If the query fails, dispatches [ERROR_FETCHING_REWARDS] action.
 */
let fetchRewards: (~uID: id, ~dispatch: storeAction => 'a) => unit;

/*
    [addTodo text points goToTodoList todoListID dispatch] queries the database,
    adding a todo with [text] and [points] to a todolist with id [todoListID].
    Returns a promise:
    - If the query is successful, calls [goToTodoList].
    - If the query fails, dispatches an [ERROR_ADDING_TODO] action.
 */
let addTodo:
  (
    ~text: string,
    ~points: int,
    ~goToTodoList: unit => 'a,
    ~todoListID: id,
    ~dispatch: addAction => 'a
  ) =>
  unit;

/*
    [addReward text points goToTodoList todoListID dispatch] queries the database,
    adding a reward with [text] and [points] to a user with id [userID].
    Returns a promise:
    - If the query is successful, calls [goToTodoList].
    - If the query fails, dispatches an [ERROR_ADDING_REWARD] action.
 */
let addReward:
  (
    ~text: string,
    ~points: int,
    ~goToTodoList: unit => 'a,
    ~userID: id,
    ~dispatch: addAction => 'a
  ) =>
  unit;

/*
   [fetchTodos todoListID dispatch] queries the database, fetching all todos
   that belong to todolist with id [todoListID].
   Returns a promise:
   - If the query is successful, dispatches [FETCHED_TODOS(todoList)] where
   [todoList] is the list of todos returned by the database.
   - If the query fails, dispatches an [ERROR_FETCHING_TODOS] action.
 */
let fetchTodos: (~todoListID: id, ~dispatch: todosAction => 'a) => unit;

/*
   [completeTodo todoID dispatch] removes a todo with id [todoID] from its
   todolist and adds the todo to the user's list of completed todos.
   Returns a promise:
   - If the query is successful, dispatches [COMPLETED_TODO(todo)] action where
   [todo] is the todo with id [todoID].
   - If the query fails, dispatches an [ERROR_COMPLETING_TODO] action.
 */
let completeTodo: (~todoID: id, ~dispatch: todosAction => 'a) => unit;

/*
   [login username password dispatch] logs in a user with [username] and [password] where
   [password] is the encrypted representation of their password.
   Returns a promise:
   - If the user is succssfully logged in, [dispatch]es [`LOGGED_IN(user)] where
   [user]  is the document with [username] and [password]
   - Otherwise dispatches [`ERROR]
 */
let login:
  (~username: string, ~password: string, ~dispatch: appAction => 'a) => unit;

/*
   [signup username password onSignup] signs up a user with [username] and
   [password] where [password] is the encrypted representation of their password.
   Returns a promise:
   - If the user is succssfully signed up, [dispatch]es [`LOGGED_IN(user)] where
   [user]  is the document with [username] and [password]
   - Otherwise dispatches [`ERROR]
 */
let signup:
  (~username: string, ~password: string, ~dispatch: appAction => 'a) => unit;