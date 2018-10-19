package Command;

import java.util.ArrayList;
import java.util.List;

public class Broker {
    //Create command invoker class

    private List<Order> orderList = new ArrayList<>();

    void placeOrder(Order order) {
        orderList.add(order);
    }

    void processOrders() {

        for (Order order : orderList)
            order.execute();

        orderList.clear();
    }

}
