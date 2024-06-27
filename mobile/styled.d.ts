import 'styled-components/native';
import {IThemeContract} from './src/assets/theme/theme.contract';

declare module 'styled-components/native' {
  export interface DefaultTheme {
    theme: IThemeContract;
    setTheme: (status?: 'light' | 'dark') => void;
  }
}
