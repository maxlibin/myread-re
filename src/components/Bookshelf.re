open Const;

let component = ReasonReact.statelessComponent("Bookshelf");

let make = (~title:string="", ~shelf:string="", ~books, _children) => {
  ...component,
  render: (_self) => {
    let books = books |> Belt.List.fromArray |> List.filter(
      book => book.shelf == shelf
    );

     /* backgroundImage: `url(${imageLinks && imageLinks.smallThumbnail})` */

    let style = ReactDOMRe.Style.make(~width="128", ~height="193", ());
    
    <div className="bookshelf">
      <h2 className="bookshelf-title">
        <span>
          (title |> RR.string)
        </span>
      </h2>
      <div className="bookshelf-books">
        <ol className="books-grid">
          {
            books
            |> List.map(
              book => <BookList key=book.title book />
            )
            |> Array.of_list
            |> ReasonReact.array
          }
        </ol>
      </div>
    </div>
  }
}