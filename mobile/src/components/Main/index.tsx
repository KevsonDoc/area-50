import {JSX, PropsWithChildren} from 'react';
import {View} from './view';

export function Main({children}: PropsWithChildren): JSX.Element {
  return <View>{children}</View>;
}
