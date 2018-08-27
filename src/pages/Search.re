open Const;

type state =
  | Loading
  | Books(array(booksType));

type action =
  | UpdateBooks(array(booksType))
  | FetchBooks(string);

module Decode = {
  let books = books =>
    Json.Decode.(
      books |> field("books", array(booktypes))
    );
};

let fetchWithHeader = (body) =>
  Fetch.fetchWithInit(
    api ++ "/search",
    Fetch.RequestInit.make(
      ~method_=Post,
      ~body=Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(body))),
      ~headers=Fetch.HeadersInit.make({
        "Accept": "application/json",
        "Authorization": "myreadrelocal123123",
        "Content-Type": "application/json"
      }),
      ()
    )
  );

let component = ReasonReact.reducerComponent("Search");

let make = (~updatePage, _children) => {
  {
    ...component,
    initialState: state => Loading,
    reducer: (action, _state) => {
      switch action {
      | FetchBooks(value) =>
        ReasonReact.SideEffects(self => {
          let body = Js.Dict.empty();
          Js.Dict.set(body, "query", Js.Json.string(value));

          Js.Promise.(
            fetchWithHeader(body)
            |> then_(Fetch.Response.json)
            |> then_(item =>
              item
              |> Decode.books
              |> item => Js.log(item) |> resolve
            )
            |> ignore
          )
        })
      | UpdateBooks(books) =>
        ReasonReact.Update(Books(books))
      };
    },
    render: (self) => {
      Js.log(self.state);
      {
        <div className="search-books">
          <div className="search-books-bar">
            <a
              href="/"
              className="close-search"
            >
              ("Close" |. RR.string)
            </a>
            <div className="search-books-input-wrapper">
              <input
                name="searchQuery"
                type_="text"
                placeholder="Search by title or author"
                onChange=(event => self.send(FetchBooks( ReactEvent.Form.target(event)##value )))
              />
            </div>
            
          </div>
          <div className="search-books-results">
            {
              switch self.state {
              | Loading =>
                <p>{"Enter something in above search box and press enter to search for your favorite books" |> RR.string}</p>
              | Books(books) => {
                Js.log(books);
                <p>{"favorite books" |> RR.string}</p>
              }
              };
            }
          </div>
        </div>
      }
    }
  }
}