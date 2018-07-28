type bookList
type state = {
  books: option(bookList)
};

let api = "https://reactnd-books-api.udacity.com";

let fetchWithHeader = Fetch.fetchWithInit(
  api ++ "/books",
  Fetch.RequestInit.make(
    ~method_=Get,
    ~headers=Fetch.HeadersInit.make({
      "Accept": "application/json",
      "Authorization": "myreadrelocal123123"
    }),
    ()
  )
);

type action =
  | UpdateBooks(bookList)
  | FetchBooks

let component = ReasonReact.reducerComponent("Home");

let make = (~updatePage, _children) => {
  ...component,

  initialState: () => {
    books: None,
  },

  didMount: self => {
    self.send(FetchBooks);
    ();
  },
  reducer: (action, state) =>
    switch action {
    | UpdateBooks(books) =>
        ReasonReact.Update({
          books: Some(books)
        });
    | FetchBooks =>
        ReasonReact.UpdateWithSideEffects(
          state,
          (self => {
            Js.Promise.(
              fetchWithHeader
              |> then_(Fetch.Response.json)
              |> then_(json => {
                  self.send(UpdateBooks(Obj.magic(json)));
                  Js.Promise.resolve();
                })
            ) |> ignore;
          })
        );
    },
  render: self => {
    let booksComponent = book => {
      Js.log(book);
      <div>
        ("hello" |. ReasonReact.string)
      </div>;
    }
    
    let booksContent = switch(self.state.books) {
    | None => ReasonReact.null
    | Some(items) => {
        Js.log(items);
        /* Js.log(books(items)); */
        <div>
          /* {booksComponent |. List.map(items) |. Array.of_list |. ReasonReact.array} */
          {"test" |. ReasonReact.string}
        </div>
      }
    };

    <div className="home">
      <div className="list-books">
        <div className="list-books-title">
          <h1>{"MyReads" |. RR.string}</h1>
          <p>{"Udacity React nanodegree MyReads project" |> RR.string}</p>
          <button
            className="btn"
            onClick=(_event => updatePage())
          >
            ("Add a book" |. RR.string)
          </button>
        </div>
        <div>
          {booksContent}
        </div>
      </div>
    </div>
  }
}
