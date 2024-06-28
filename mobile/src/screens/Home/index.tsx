import {JSX, useContext, useEffect} from 'react';
import {ThemeContext} from 'styled-components/native';
import {HomeView} from './view';

export default function HomeScreen(): JSX.Element {
  const themeContext = useContext(ThemeContext);

  useEffect(() => {
    console.log(themeContext);
  }, [themeContext]);

  return <HomeView />;
}
