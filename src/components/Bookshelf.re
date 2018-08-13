open Const;

let component = ReasonReact.statelessComponent("Bookshelf");

let make = (~title:string="", ~shelf:string="", ~books, _children) => {
  ...component,
  render: (_self) => {
    let books = books |> Belt.List.fromArray |> List.filter(
      book => book.shelf == shelf
    );

    Js.log(books);
    
    <div className="bookshelf">
      <h2 className="bookshelf-title">
        <span>
          (title |> RR.string)
        </span>
      </h2>
      <div className="bookshelf-books">
        <ol className="books-grid">
          <div className="book">
            <div className="book-top">
              /* <div className="book-cover" style=style></div> */
              <div className="book-shelf-changer">
              </div>
            </div>
          </div>
        </ol>
      </div>
    </div>
  }
}