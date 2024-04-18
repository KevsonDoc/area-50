import { Controller } from '@nestjs/common';
import { MessagePattern, Payload } from '@nestjs/microservices';
import { MqttService } from './mqtt.service';
import { DHT11SensorDto } from './dto/dht11-sensor.dto';

@Controller()
export class MqttController {
  constructor(private readonly mqttService: MqttService) {}

  @MessagePattern('sensor')
  create(@Payload() data: DHT11SensorDto) {
    return this.mqttService.insert(data);
  }
}
