let component = ReasonReact.statelessComponent("BookContent");

let make = (~books, _children) => {
  ...component,
  render: _self => {
    let booksComponent = book => {
      let style = ReactDOMRe.Style.make(
        ~width="128px",
        ~height="193px",
        ~backgroundImage="url(" ++ book##imageLinks##smallThumbnail ++ ")",
        ()
      );

      <li>
        <div className="book">
          <div className="book-top">
            <div className="book-cover" style=style></div>
            <div className="book-shelf-changer">
            </div>
          </div>
          <div className="book-title">{book##title}</div>
          <div className="book-authors">
            {book##author}
          </div>
        </div>
      </li>;
    };

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
}
