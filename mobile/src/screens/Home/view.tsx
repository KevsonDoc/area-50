import {View, Text} from 'react-native';
import React from 'react';
import * as S from './styles';
import {Main} from '../../components/Main';

export function HomeView() {
  return (
    <Main>
      <S.Container>
        <View>
          <Text>HomeView</Text>
        </View>
      </S.Container>
    </Main>
  );
}
