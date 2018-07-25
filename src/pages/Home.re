type booksList = {
  
};

type state = {
  books: list(booksList)
};

type action = 
  | Books(list(books));

let component = ReasonReact.reducerComponent("Home");

let make = (~updatePage, _children) => {
  ...component,

  didMount: self => {
    Js.Promise.(
      BooksAPI.getAll()
      |> then_(result =>
        resolve(self.send(Books(result)))
      )
      |> ignore
    )
  },

  willReceiveProps: self => {
    Js.log(self.state)
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
