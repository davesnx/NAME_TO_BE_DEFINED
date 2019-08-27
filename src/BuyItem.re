[@react.component]
let make = (~item: Model.Item.t, ~onAccept, ~onReject) =>
  <div>
    <h1> {ReasonReact.string(item.name)} </h1>
    <div>
      <button onClick=onAccept> {ReasonReact.string("Accept")} </button>
      <button onClick=onReject> {ReasonReact.string("Reject")} </button>
    </div>
  </div>;
