open ReactNative;
open Style;

/* let gradient = "background: linear-gradient(139.75deg, #F58959 0.88%, #E76A33 87.91%)"; */

module Color = {
  let grey = "#8792A8";
  let lightgrey = "#F7F7FA";
  let darkblue = "#203152";
  let white = "#FFFFFF";
  let orange = "#E76A33";
  let black = "#000000";
};

module Typo = {
  let h1 =
    textStyle(
      ~fontSize=56.,
      ~lineHeight=56.,
      ~fontWeight=`bold,
      ~color=Color.darkblue,
      (),
    );
  let h2 =
    textStyle(
      ~fontSize=24.,
      ~lineHeight=24.,
      ~fontWeight=`bold,
      ~color=Color.darkblue,
      (),
    );
  let h3 =
    textStyle(
      ~fontSize=24.,
      ~lineHeight=24.,
      ~fontWeight=`_600,
      ~color=Color.darkblue,
      (),
    );
  let h4 =
    textStyle(
      ~fontSize=20.,
      ~lineHeight=20.,
      ~fontWeight=`bold,
      ~color=Color.darkblue,
      (),
    );
  let bo =
    textStyle(
      ~fontSize=17.,
      ~lineHeight=17.,
      ~fontWeight=`_400,
      ~color=Color.darkblue,
      (),
    );
  let di =
    textStyle(
      ~fontSize=16.,
      ~lineHeight=16.,
      ~fontWeight=`_400,
      ~color=Color.darkblue,
      (),
    );
};
