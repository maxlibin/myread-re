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
              |> then_(item => {
                  let res = Js.Json.(item);
                  self.send(UpdateBooks(Obj.magic(item)));
                  Js.Promise.resolve();
                })
            ) |> ignore;
          })
        );
    },
  render: self => {
    let booksComponent = book => {
      <li>
        <div className="book">
          <div className="book-top">
            <div className="book-cover"></div>
            <div className="book-shelf-changer">
            </div>
          </div>
          <div className="book-title">{book##title}</div>
          <div className="book-authors">
            {book##author}
          </div>
        </div>
      </li>;
    }
    
    let booksContent = switch(self.state.books) {
    | None => ReasonReact.null
    | Some(items) => {
        /* let books = Obj.magic(items)##books; */
        let books = Obj.magic(items)##books;
        <div className="list-books-content">
          <div className="bookshelf">
            <h2 className="bookshelf-title">
              <span>("books" |. ReasonReact.string)</span>
            </h2>
            <div className="bookshelf-books">
              <ol className="books-grid">
                {booksComponent |. Array.map(books) |. ReasonReact.array}
              </ol>
            </div>
          </div>
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
      </div>
      {booksContent}
    </div>
  }
}
