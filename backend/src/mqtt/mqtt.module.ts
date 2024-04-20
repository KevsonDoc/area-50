import { Module } from '@nestjs/common';
import { MqttController } from './mqtt.controller';
import { MqttService } from './mqtt.service';
import { DatabaseModule } from 'src/database/database.module';
import { mqttProviders } from './mqtt.providers';

@Module({
  imports: [DatabaseModule],
  controllers: [MqttController],
  providers: [MqttService, ...mqttProviders],
})
export class MqttModule {}
