open Const;


type state =
  | Loading
  | Books(array(booksType));

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
  | UpdateBooks(array(booksType))
  | FetchBooks;

module Decode = {
  let books = books =>
    Json.Decode.(
      books |> field("books", array(booktypes))
    );
};

let component = ReasonReact.reducerComponent("Home");

let make = (~updatePage, _children) => {
  ...component,

  initialState: _state => Loading,

  didMount: self => self.send(FetchBooks),

  reducer: (action, state) =>
    switch action {
    | FetchBooks =>
        ReasonReact.UpdateWithSideEffects(
          state,
          (self => {
            Js.Promise.(
              fetchWithHeader
              |> then_(Fetch.Response.json)
              |> then_(item =>
                item
                |> Decode.books
                |> item => self.send(UpdateBooks(item))
                |> resolve
              )
              |> ignore
            );
          })
        )
    | UpdateBooks(books) =>
      ReasonReact.Update(Books(books))
    },
  render: self => {
    switch(self.state) {
    | Loading =>
      <div className={"bookshelfLoading"}>
        <span className="loader" /> ("Loading..." |. RR.string)
      </div>
    | Books(books) =>
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

        <div className="list-books-content">
          {
            let bookshelfsComponent = shelfs => {
              <Bookshelf
                key=shelfs.key
                shelf=shelfs.key
                title=shelfs.title
                books=books
              />
            };
  
            bookshelfs
            |> List.map(bookshelfsComponent)
            |> Array.of_list
            |> ReasonReact.array
          }
        </div>
      </div>
    };
  }
}
