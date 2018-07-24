type booksList = [];

type state = {
  books: booksList
};

type action = 
  | Books(booksList);

let component = ReasonReact.reducerComponent("Home");

let make = (~updatePage, _children) => {
  ...component,

  didMount: self => {
    BooksAPI.getAll
    |. Js.Promise.then_(result =>
      self.send(Books(result))
    )
  },

  initialState: () => {
    books: [],
  },

  reducer: (action, state)=> {
    switch action {
    | Books(books) => ReasonReact.Update({
        books: books
      })
    };
  },

  render: _self =>
    <div className="home">
      <div className="list-books">
        <div className="list-books-title">
          <h1>{"MyReads" |> RR.string}</h1>
          <p>{"Udacity React nanodegree MyReads project" |> RR.string}</p>
          <button
            className="btn"
            onClick=(_event => updatePage())
          >
            {"Add a book" |> RR.string}
          </button>
        </div>
      </div>
    </div>
}
