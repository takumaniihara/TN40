# The default keymap for TN40

## キーマップ紹介

### QWERTY

```
Qwerty
,-----------------------------------------------------------------------------------.
| Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
|------+------+------+------+------+-------------+------+------+------+------+------|
|CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  -   |
|------+------+------+------+------+------|------+------+------+------+------+------|
|Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
|------+------+------+------+------+------+------+------+------+------+------+------|
| VIM  | WIN  | ALT  | OS   |v/En  |Space |Shift |^/Ja  |MEDIA |      |      |Enter |
`-----------------------------------------------------------------------------------'
```

一般的な文字入力`QWERTY`モード．デフォルトのレイヤーですべてのレイヤーはここからアクセスする(他のレイヤーを使っていても必ずこのレイヤーに戻ってくる)．

- CtlEsc : タップでEsc，ホールドでCtrl
- VIM,OS,MEDIA : それぞれのレイヤーへ切り替え
- v/En : タップで英語入力切り替え，ホールドでLOWERレイヤーへ切り替え
- ^/Ja : タップで日本語入力切り替え，ホールドでRAISEレイヤーへ切り替え

### LOWER

```
 LOWER 
,-----------------------------------------------------------------------------------.
|  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      |      |      |      | x    |   4  |   5  |   6  |   +  |  *   |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |      |      |      |      |      | x    |   1  |   2  |   3  |   /  |  -   |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |<<v>> |      |   0  |      |   0  |   .  |Enter |Enter |
`-----------------------------------------------------------------------------------'
```

`QWERTY`レイヤーにて`v/En`が長押されると起動．主に数字入力に使用

- 右手がテンキーと同じレイアウトになる．(右手がテンキーに移動するのではなくてテンキーが右手に来る)

### RAISE

```
RAISE
,-----------------------------------------------------------------------------------.
|  ~   |      |      |  _   |  -   |      |      |  =   |  +   |  {   |  }   |  |   |
|------+------+------+------+------+-------------+------+------+------+------+------|
|  `   |  !   |  @   |  #   |  $   |   %  |  ^   |  &   |  *   |  (   |  )   |  \   | 
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |  [   |  ]   |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |<<^>> |      |      |      |      |
`-----------------------------------------------------------------------------------'
```

`QWERTY`レイヤーにて`^/Ja`が長押されると起動．主に記号入力に使用

- 一般的な英語キーボードの記号配列と同じだが，ホームポジションでほとんどの記号が入力可能

### VIM

```
VIM
,-----------------------------------------------------------------------------------.
|      |      |Word  | END  |      |      | Yank | PGUP | INST | HOME |Paste | DEL  |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      | PGDN |      |      | Left | Down |  Up  |Right |      |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |      |      |      |      |BWord |      |      |      |      |Find/ |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
| <<V>>|      |      |      |      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```

`QWERTY`レイヤーにて`VIM`が押されると起動．VIMエディタと同じような動作が可能なモード

- 矢印入力 : HJKL
- コピペ
- PageUp,Down

などが可能

### OS (Windows)

```
WINDOWS OS 
,-----------------------------------------------------------------------------------.
|      |ALT+F4|      |FBrows|      |      |      |      |      |      |CLIPB |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |Enter | Cut  | Copy |Paste |      |      | ^TAB |S^TAB |      |      |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|<<SF>>|      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |<<OS>>|      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
WINDOWS OS SHIFT (OSモードにてShiftが押されると)
,-----------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|<<SF>>|      |      |ALT+F4|      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |<<OS>>|      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```

`QWERTY`レイヤーにて`OS`が押されると起動．Windowsの便利ショートカット

- ウィンドウの選択 CTRL+TAB
- ウィンドウの移動 Alt+Space -> M , Win + arrow
- 仮想デスクトップの移動 windows + ctrl + arrow
- ウィンドウの削除 Alt + F4
- ファイルブラウザの起動 Win + e
- クリップボード Win + v
- コピー・ペースト・カット ctrl + cvx


### ADJUST

```
ADJUST
,-----------------------------------------------------------------------------------.
|PrtSc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
|------+------+------+------+------+-------------+------+------+------+------+------|
| LED1 | LED2 | LED3 | LED4 |      |RGBRST|x     |  F4  |  F5  |  F6  |x     | F12  |
|------+------+------+------+------+------|------+------+------+------+------+------|
| LED5 | LED6 | LED7 | LED8 |      |      |x     |  F1  |  F2  |  F3  |x     |x     |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |<<v>> |ENGOS |JPNOS |<<^>> |      | MREC |MRECS |MPLAY |     
`-----------------------------------------------------------------------------------'
```
`QWERTY`レイヤーにて `v/En`と`^/Ja`が同時に押されると起動．Windowsの便利ショートカット

- ファンクションキーの入力(F1 ~ F12)
- 英語配列PC,日本語配列PCへの切り替えキー `ENGOS`, `JPNOS`
- 左右のLEDモードがおかしくなったときのリセット `RGBRST`
- LEDの設定
  - LED1 : LED機能のON/OFF切り替え
  - LED2 : LEDパターンの切り替え
  - LED3 : LEDの明るさを増やす
  - LED4 : LEDの明るさをへらす
  - LED5 : LEDの色相を増やす
  - LED6 : LEDの色相を減らす
  - LED7 : LEDの色の彩度を増やす
  - LED8 : LEDの色の彩度を減らす
- ダイナミックマクロ (電源を消すと消えるマクロ)
  - MREC : マクロ記録開始
  - MRECS : マクロ記録終了
  - MPLAY : 記録したマクロを再生


## LEDパターン一覧

- RGB_MATRIX_SOLID_COLOR,     // Static single hue, no speed support
- RGB_MATRIX_ALPHAS_MODS,         // Static dual hue, speed is hue for secondary hue
- RGB_MATRIX_GRADIENT_UP_DOWN,    // Static gradient top to bottom, speed controls how much gradient changes
- RGB_MATRIX_GRADIENT_LEFT_RIGHT,    // Static gradient left to right, speed controls how much gradient changes
- RGB_MATRIX_BREATHING,           // Single hue brightness cycling animation
- RGB_MATRIX_BAND_SAT,        // Single hue band fading saturation scrolling left to right
- RGB_MATRIX_BAND_VAL,        // Single hue band fading brightness scrolling left to right
- RGB_MATRIX_BAND_PINWHEEL_SAT,   // Single hue 3 blade spinning pinwheel fades saturation
- RGB_MATRIX_BAND_PINWHEEL_VAL,   // Single hue 3 blade spinning pinwheel fades brightness
- RGB_MATRIX_BAND_SPIRAL_SAT,     // Single hue spinning spiral fades saturation
- RGB_MATRIX_BAND_SPIRAL_VAL,     // Single hue spinning spiral fades brightness
- RGB_MATRIX_CYCLE_ALL,           // Full keyboard solid hue cycling through full gradient
- RGB_MATRIX_CYCLE_LEFT_RIGHT,    // Full gradient scrolling left to right
- RGB_MATRIX_CYCLE_UP_DOWN,       // Full gradient scrolling top to bottom
- RGB_MATRIX_CYCLE_OUT_IN,        // Full gradient scrolling out to in
- RGB_MATRIX_CYCLE_OUT_IN_DUAL,   // Full dual gradients scrolling out to in
- RGB_MATRIX_RAINBOW_MOVING_CHEVRON,  // Full gradent Chevron shapped scrolling left to right
- RGB_MATRIX_CYCLE_PINWHEEL,      // Full gradient spinning pinwheel around center of keyboard
- RGB_MATRIX_CYCLE_SPIRAL,        // Full gradient spinning spiral around center of keyboard
- RGB_MATRIX_DUAL_BEACON,         // Full gradient spinning around center of keyboard
- RGB_MATRIX_RAINBOW_BEACON,      // Full tighter gradient spinning around center of keyboard
- RGB_MATRIX_RAINBOW_PINWHEELS,   // Full dual gradients spinning two halfs of keyboard
- RGB_MATRIX_RAINDROPS,           // Randomly changes a single key's hue
- RGB_MATRIX_JELLYBEAN_RAINDROPS, // Randomly changes a single key's hue and saturation
- RGB_MATRIX_TYPING_HEATMAP,      // How hot is your WPM!
- RGB_MATRIX_DIGITAL_RAIN,        // That famous computer simulation
- RGB_MATRIX_SOLID_REACTIVE_SIMPLE,   // Pulses keys hit to hue & value then fades value out
- RGB_MATRIX_SOLID_REACTIVE,      // Static single hue, pulses keys hit to shifted hue then fades to current hue
- RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
- RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
- RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
- RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
- RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
- RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
- RGB_MATRIX_SPLASH,              // Full gradient & value pulse away from a single key hit then fades value out
- RGB_MATRIX_MULTISPLASH,         // Full gradient & value pulse away from multiple key hits then fades value out
- RGB_MATRIX_SOLID_SPLASH,        // Hue & value pulse away from a single key hit then fades value out
- RGB_MATRIX_SOLID_MULTISPLASH,   // Hue & value pulse away from multiple key hits then fades value out


