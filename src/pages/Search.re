open Const;

type state = {
  books: array(booksType)
};

type action =
  | UpdateBooks(array(booksType))
  | FetchBooks(ReactEvent.Form.t);

module Decode = {
  let books = books =>
    Json.Decode.(
      books |> field("books", array(booktypes))
    );
};

let fetchWithHeader = (payload) =>
  Fetch.fetchWithInit(
    api ++ "/search",
    Fetch.RequestInit.make(
      ~method_=Post,
      ~body=Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(payload))),
      ~headers=Fetch.HeadersInit.make({
        "Accept": "application/json",
        "Authorization": "myreadrelocal123123"
      }),
      ()
    )
  );

let component = ReasonReact.reducerComponent("Search");

let make = (~updatePage, _children) => {
  /* let handleOnChange = (e) => {
    let target = ReactEvent.Form.target(e);

    Js.log(target##value);
  }; */

  {
    ...component,
    initialState: state => {
      books: [||]
    },
    reducer: (action, _state) => {
      switch action {
      | FetchBooks(value) =>
        ReasonReact.SideEffects(self => {
          
          Js.log(value);


          /* let payload = Js.Dict.empty();
          Js.Dict.set(payload, "query", Js.Json.string(target##value));
          Js.Dict.set(payload, "maxResult", Js.Json.string("20"));

          Js.Promise.(
            fetchWithHeader(payload)
            |> then_(Fetch.Response.json)
            |> then_(item =>
              item
              |> Decode.books
              |> item => self.send(UpdateBooks(item))
              |> resolve
            )
            |> ignore
          ) */
        })
      | UpdateBooks(books) =>
        ReasonReact.Update({
          books: books
        })
      };
    },
    render: (self) => {
      Js.log(self.state.books);
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
            <p>{"Enter something in above search box and press enter to search for your favorite books" |> RR.string}</p>
          </div>
        </div>
      }
    }
  }
}