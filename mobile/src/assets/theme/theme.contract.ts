export interface IThemeContract {
  title: 'dark' | 'light';
  colors: {
    primary: string;
    secondary: string;
    background: string;
    emphasis: string;
    text: string;
  };
}
