open ReactNative;
open Style;

module Spacer = {
  let unit = v => float_of_int(v * 8)->dp;

  let style = (~top, ~left, ~right, ~bottom) =>
    viewStyle(
      ~marginTop=unit(top),
      ~marginLeft=unit(left),
      ~marginBottom=unit(bottom),
      ~marginRight=unit(right),
      (),
    );

  [@react.component]
  let make = (~top=0, ~left=0, ~right=0, ~bottom=0, ~children=?) =>
    <View style={style(~top, ~left, ~right, ~bottom)}>
      {Belt.Option.getWithDefault(children, React.null)}
    </View>;
};

module FloatingButton = {
  let style =
    viewStyle(
      ~shadowOffset=offset(~height=2., ~width=7.),
      ~shadowRadius=25.,
      ~shadowColor="rgba(102, 0, 17, 0.2)",
      ~backgroundColor="#F58959",
      ~flex=1.,
      ~justifyContent=`center,
      ~alignItems=`center,
      ~width=65.->dp,
      ~height=65.->dp,
      ~borderRadius=32.,
      (),
    );

  [@react.component]
  let make = (~title, ~onPress) =>
    <View style> <Button title onPress color=Theme.Color.white /> </View>;
};
