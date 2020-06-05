open Types;

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
let addTodo: (~text: string, ~points: int, ~goToTodoList: unit => 'a, 
~todoListID: id, ~dispatch: addAction => 'a) => unit;

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