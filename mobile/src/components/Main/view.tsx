import {JSX, PropsWithChildren} from 'react';
import * as Styles from './styles';

export function View({children}: PropsWithChildren): JSX.Element {
  return <Styles.MainContainer>{children}</Styles.MainContainer>;
}
