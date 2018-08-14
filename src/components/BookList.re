open Const;

let component = ReasonReact.statelessComponent("BookList");

let make = (~book, _children) => {
  ...component,
  render: (_self) => {
     /* backgroundImage: `url(${imageLinks && imageLinks.smallThumbnail})` */


    let style = ReactDOMRe.Style.make(~width="128px", ~height="193px", ~backgroundImage="url("++book.imageLinks.smallThumbnail++")", ());

    <li>
      <div className="book">
        <div className="book-top">
          <div className="book-cover" style=style></div>
          <div className="book-shelf-changer">
            /* <Select
              onChange={this.handleOnChange}
              currentValue={shelf ? shelf : "none"}
            /> */
          </div>
        </div>
        <div className="book-title">
          {book.title |> RR.string}
        </div>
        <div className="book-authors">
        {
          book.authors
          |> List.map(
            author => <span key=author>{author |> RR.string}</span>
          )
          |> Array.of_list
          |> ReasonReact.array
        }
        </div>
      </div>
    </li>
  }
}