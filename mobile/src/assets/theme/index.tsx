import type {PropsWithChildren} from 'react';
import {JSX, useReducer} from 'react';
import {ThemeProvider} from 'styled-components/native';
import {dark} from './dark';
import {light} from './light';
import {IThemeContract} from './theme.contract';

function reducer(
  state: IThemeContract,
  action: 'light' | 'dark',
): IThemeContract {
  if (action === 'dark') {
    return dark;
  }

  return light;
}

export default function Theme({children}: PropsWithChildren): JSX.Element {
  const [theme, dispatch] = useReducer(reducer, light);

  return (
    <>
      <ThemeProvider
        theme={{
          theme,
          setTheme: (status?: 'light' | 'dark') => {
            if (status) {
              dispatch(status);
            } else {
              dispatch(theme.title === 'dark' ? 'light' : 'dark');
            }
          },
        }}>
        {children}
      </ThemeProvider>
    </>
  );
}
