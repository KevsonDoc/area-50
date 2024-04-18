import { PartialType } from '@nestjs/mapped-types';
import { CreateMqttDto } from './dht11-sensor.dto';

export class UpdateMqttDto extends PartialType(CreateMqttDto) {
  id: number;
}
