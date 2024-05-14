import {StyleSheet, Text, View} from 'react-native';
import {Button} from '../../components/Buttton';
import {NavigationType} from '../../types/route';

interface HistoryScreenProps {
  navigation: NavigationType;
}

export function HistoryScreen({navigation}: HistoryScreenProps) {
  return (
    <View style={styles.container}>
      <Button
        type="outline"
        onPress={() => {
          navigation.goBack();
        }}
        title="Voltar"
      />
      <Text>Hello World History</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    gap: 10,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#FFF',
  },
});
